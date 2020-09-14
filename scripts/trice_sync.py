#!/usr/bin/env python

"""Example trice usage to sync all Doorstop requirements with a GitLab label."""

import sys
import doorstop

from contextlib import asynccontextmanager
from trice import gitlab
from trice.cli import get_api
from trice.utils import asyncio_run
from aiohttp.client_exceptions import ClientResponseError
from yarl import URL

# Project location and label color
project_url = URL('https://gitlab.com/MaplessAI/external/requirements-testing')
color = 'red'

@asyncio_run
async def sync_labels():
    tree = doorstop.build()
    print(f"Document tree structure: {tree}")

    async with get_api(project_url) as api:
        for doc_name in tree.documents:
            print(f"Parsing document: {doc_name}")
            document = tree.find_document(doc_name)
            count = sum(1 for item in document if item.active)
            print(f"{count} active items in {document}")
            # sync all items
            for item in document.items:
                if item.normative:
                    try:
                        label = await api.projects.labels.create(project_url.path.strip('/'),
                                                                 data={'name': f'{item.uid}', 'color': color},
                                                                 model=True)
                        print(f"Created label {item.uid}")
                    except ClientResponseError as err:
                        print(f"ClientResponseError: {err.message}")

if __name__ == "__main__":
    sync_labels()
