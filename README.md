# Requirements Playground

A space for experimenting with GitLab requirements management functions.
Requirements are specified in YAML files that can be managed using [Doorstop](https://doorstop.readthedocs.io/en/latest/).

## Publish requirements report

The requirements report for this repo can be published using Doorstop. First, run integrity checks:

```console
$ doorstop
building tree...
loading documents...
validating items...

SYS
│   
├── SYSVER
│   
└── SWRS
    │   
    └── SWVER
```

Then publish requirements documents in HTML format:

```console
$ doorstop publish all ./public
building tree...
loading documents...
publishing tree to './requirements-playground/public'...
published: ./requirements-playground/public
```
