# debian-createstructure
[![GitHub license](https://img.shields.io/badge/license-GNU-green?style=flat)](https://github.com/createstructure/debian-createstructure/blob/main/docs/LICENSE)
![Author](https://img.shields.io/badge/author-Castellani%20Davide-green?style=flat)
![sys.platform supported](https://img.shields.io/badge/OS%20platform%20supported-all-blue?style=flat) 

##  Description 
Debian client app
![createstructure/debian-createstructure](https://opengraph.githubassets.com/fc1bc3722cd31b2e2ba43f4700a3bf83420a40e8657a693e0e5187f05a69e6c0/createstructure/debian-createstructure)
##  Class UML 
![Class UML](https://raw.githubusercontent.com/createstructure/debian-createstructure/main/docs/debian-createstructure-Class-UML.svg)
##  Directory structure 

```
../repo
├── Makefile
├── bin # source code
│   ├── createstructure.cpp
│   ├── global-libraries
│   │   ├── bin # source code
│   │   │   ├── cryptation.hpp
│   │   │   ├── emoji.hpp
│   │   │   ├── inputs.hpp
│   │   │   ├── json.hpp
│   │   │   ├── positive.hpp
│   │   │   ├── rest.hpp
│   │   │   └── sleep.hpp
│   │   └── docs # documentation
│   │       ├── CHANGELOG.md
│   │       ├── LICENSE
│   │       ├── README.md
│   │       ├── libraries-createstructure-Class-UML.svg
│   │       └── libraries-createstructure.drawio
│   └── local-libraries
│       ├── create.hpp
│       ├── help.hpp
│       ├── login.hpp
│       ├── settings.hpp
│       └── version.hpp
├── createstructure.1
├── createstructure.2
├── createstructure.in
├── debian # debian control code
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
└── docs # documentation
    ├── LICENSE
    ├── README.md
    ├── debian # debian control code-createstructure-Class-UML.svg
    └── debian-createstructure.drawio

8 directories, 36 files
```
createstructure (10.01.08) focal; urgency=medium

  * [Added charts automation](https://github.com/createstructure/debian-createstructure/issues/7)

 -- Castellani Davide <help@castellanidavide.it>  Sat, 12 Mar 2022 11:00:00 +1000

createstructure (10.01.07) focal; urgency=medium

  * [Add sponsorship button](https://github.com/createstructure/createstructure.github.io/issues/36)

 -- Castellani Davide <help@castellanidavide.it>  Wed, 5 Jan 2022 14:00:00 +1000

createstructure (10.01.06) focal; urgency=medium

  * Fixed a few bugs

 -- Castellani Davide <help@castellanidavide.it>  Tue, 21 Dec 2021 20:00:00 +1000

createstructure (10.01.05) focal; urgency=medium

  * Fixed a few bugs

 -- Castellani Davide <help@castellanidavide.it>  Tue, 21 Dec 2021 18:30:00 +1000

createstructure (10.01.04) focal; urgency=medium

  * Fixed a few bugs

 -- Castellani Davide <help@castellanidavide.it>  Tue, 21 Dec 2021 18:00:00 +1000

createstructure (10.01.03) focal; urgency=medium

  * [Optimize login, make it easier](https://github.com/createstructure/debian-createstructure/issues/6)

 -- Castellani Davide <help@castellanidavide.it>  Tue, 21 Dec 2021 16:15:00 +1000

createstructure (10.01.02) focal; urgency=medium

  * Commented DEBUG define

 -- Castellani Davide <help@castellanidavide.it>  Thu, 16 Dec 2021 15:30:00 +1000

createstructure (10.01.01) focal; urgency=medium

  * [Adapt Debian application to the new REST API](https://github.com/createstructure/manager-createstructure/issues/2)
  * [Make it easier for the consumer the login management](https://github.com/createstructure/manager-createstructure/issues/3)

 -- Castellani Davide <help@castellanidavide.it>  Fri, 10 Dec 2021 22:00:00 +1000

createstructure (09.01.06) focal; urgency=medium

  * Fixed a problem of an [issue](https://github.com/createstructure/libraries-createstructure/issues/1)

 -- Castellani Davide <help@castellanidavide.it>  Fri, 10 Sep 2021 23:00:00 +1000

createstructure (09.01.05) focal; urgency=medium

  * Fixed an [issue](https://github.com/createstructure/libraries-createstructure/issues/1)

 -- Castellani Davide <help@castellanidavide.it>  Fri, 10 Sep 2021 22:15:00 +1000

createstructure (09.01.04) focal; urgency=medium

  * Updated libraries to v09.01.11
  * Updated .gitignore file

 -- Castellani Davide <help@castellanidavide.it>  Sun, 18 Jul 2021 14:15:00 +1000

createstructure (09.01.03) focal; urgency=medium

  * Optimized libraries management

 -- Castellani Davide <help@castellanidavide.it>  Sun, 18 Jul 2021 11:15:00 +1000

createstructure (09.01.02) focal; urgency=medium

  * Fixed a bug

 -- Castellani Davide <help@castellanidavide.it>  Sat, 17 Jul 2021 18:45:00 +1000

createstructure (09.01.01) focal; urgency=medium

  * Initial version

 -- Castellani Davide <help@castellanidavide.it>  Sat, 17 Jul 2021 18:30:00 +1000
##  Rebuild the debian-createstructure locally 
Install the manager-create locally permits you to do some debug and try new configurations.

### Steps:
- [ Rebuild the debian-createstructure locally ](#octocat-rebuild-the-debian-createstructure-locally-octocat)
  - [Steps:](#steps)
  - [1. Install VirtualBox on the PC](#1-install-virtualbox-on-the-pc)
  - [2. Install Ubuntu](#2-install-ubuntu)
  - [3. Install dependencies](#3-install-dependencies)
  - [4. Compile](#4-compile)

### 1. Install VirtualBox on the PC
For installation we suggest VirtualBox, a tool that allows you to create one or more virtual machines :computer:.
If any of these crashes, in any case, your PC will not lose data, at most you will have to restart it :smile:.

To install VirtualBox on your PC you need to:
- Get in into the UEFI
- Enable the function which name is like "Virtualization" (for each UEFI this step is different but similar)
- Save the configuration and restart the PC
- Go to the [VirtualBox website](https://www.virtualbox.org/)
- Press "Download"
- Run the downloaded file
- Follow the installation steps

### 2. Install Ubuntu
As the OS we suggest to use Ubuntu, because it is lightweight (for RAM and CPU) and it's free.

To install Ubuntu on VirtualBox you need to:
- Download the last LTS version of Ubuntu by the following link: [https://ubuntu.com/download/desktop](https://ubuntu.com/download/desktop)
> Now you can continue with the other steps during the download
- Open VirtualBox
- Press "New"
- Compile the form
    - As name put "rest-createstructure"
    - As Type: "Linux"
    - As version: "Ubuntu (64-bit)" or "Ubuntu (32-bit)"
    - Press "Next >"
- Set the RAM to use for the VirtualMachine, at most half of local RAM and press "Next >"
- Leave "Create a virtual hard disk now" and press "Create"
- Leave "VDI ..." and press "Next >"
- Leave "Dynamically allocated" and press "Next >"
- Change the hard disk memory, we suggest 16GB and press "Create"
> Make sure that Ubuntu download is finished before to continue
- On the VirtualBox console, selecting the created VM, press "Start"
- Select as start-up disk Ubuntu, already downloaded
    - Press the folder icon
    - Press "Add", in the top menu
    - Select the Ubuntu iso, the file will have a structure like "ubuntu-version-other_info.iso"
    - Press "Choose" and "Start"
- Follow the install steps (the installation needs some minutes)

### 3. Install dependencies
Now you have to install building dependencies.
To install Dependes on the Virtual Machine you need to:
- On the VM (Virtual Machine) open the terminal (`Ctrl + Alt + T`)
- On the terminal paste `sudo apt update; sudo add-apt-repository ppa:jyrki-pulliainen/dh-virtualenv -y; sudo apt-get install git build-essential debhelper devscripts equivs dh-virtualenv python3.8 gnupg gnupg2 libcurl4-openssl-dev libssl-dev -y; git clone https://github.com/createstructure/debian-createstructure; cd debian-createstructure; echo "3.0 (native)" > ./debian/source/format` and insert password

### 4. Compile
To compile type: `dpkg-buildpackage -us -uc`
Now the .deb file is in the .. folder, you can install it with apt.

---
Made w/ :heart: by Castellani Davide

If you want to contribute you can start with:
- [Discussion](https://github.com/createstructure/debian-createstructure/discussions)
- [Issue](https://github.com/createstructure/debian-createstructure/issues/new)
