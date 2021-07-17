# debian-createstructure
[![GitHub license](https://img.shields.io/badge/license-GNU-green?style=flat)](https://github.com/CastellaniDavide/debian-createstructure-debian-createstructure/blob/master/LICENSE) ![Author](https://img.shields.io/badge/author-Castellani%20Davide-green?style=flat) ![Version](https://img.shields.io/badge/version-v1.0-blue?style=flat) ![Language ...](https://img.shields.io/badge/language-...-yellowgreen?style=flat) ![sys.platform supported](https://img.shields.io/badge/OS%20platform%20supported-...-blue?style=flat) [![On GitHub](https://img.shields.io/badge/on%20GitHub-True-green?style=flat&logo=github)](https://github.com/createstructure/debian-createstructure)

## Description
Repo containing the clientside for Ubuntu/Debian

## Table of contents
- [debian-createstructure](#debian-createstructure)
  - [Description](#description)
  - [Table of contents](#table-of-contents)
  - [Directories structure](#directories-structure)
  - [Installation](#installation)
    - [Requirements](#requirements)
    - [Install](#install)
    - [Run](#run)
  - [Repo dependencies](#repo-dependencies)


## Directories structure
```
├── bin
│   ├── libraries
│   │   └── ...
│   └── createstructure.cpp
├── debian
│   ├── changelog
│   ├── compat
│   ├── control
│   ├── copyright
│   ├── createstructure.dirs
│   ├── postinst
│   ├── postrm
│   ├── preinst
│   ├── rules
│   └── source
│       └── format
├── docs
│   ├── LICENSE
│   └── README.md
├── .git
│   └── ...
├── .github
│   └── workflows
│       └── publish.yml
├── Makefile
├── createstructure.1
└── requirements.in

```

## Installation
### Requirements
 - apt
 
### Install
 - `sudo add-apt-repository ppa:castellanidavide/createstructure; sudo apt update; sudo apt install createstructure`

### Run
 - `createstructure`

## Repo dependencies
 - [nlohmann/json](https://github.com/nlohmann/json)


---
Made w/ :love: by Castellani Davide 
If you have any problem please contact me:
- [Discussion](https://github.com/createstructure/createstructure/discussions/new) and choose "createstructure-createstructure" category
- [Issue](https://github.com/createstructure/createstructure-createstructure/issues/new)
- [help@castellanidavide.it](mailto:help@castellanidavide.it)
