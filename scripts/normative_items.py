#!/usr/bin/env python

"""Example Doorstop API usage to extract all normative items."""

import sys
import doorstop

tree = doorstop.build()
print(f"Document tree structure: {tree}")

for doc_name in tree.documents:
    print(f"Parsing document: {doc_name}")
    document = tree.find_document(doc_name)
    count = sum(1 for item in document if item.active)
    print(f"{count} active items in {document}")
    # list all items
    for item in document.items:
        if item.normative:
            print(f"{item.uid}")
