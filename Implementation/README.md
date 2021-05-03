# Reference Implementation of the Open Fax Format/Specification
## Contents
```
.
├── LICENSE
├── README.md
└── src
    ├── Client
    └── Server
```

## License
##### The reference implementation for the Open Fax Format/Specification is licensed under [GPLv3](http://www.gnu.org/licenses/lgpl-3.0.en.html).
You [MUST](https://www.faa.gov/about/initiatives/plain_language/articles/mandatory/) publish any modifications made to this implementation with the GNU General Public License Version 3 or higher and comply with the license. [See this page on ChooseALicense.com for a brief overview on the license](https://choosealicense.com/licenses/gpl-3.0/).

## Building
### Dependencies:
* meson
* libgtk-3-dev
* libgranite-dev
* libsoup2.4-dev
* libpoppler-glib-dev
* libcairo2-dev
* libglib2.0-dev
* ninja-build
* valac

For Debian based systems, you can run this command:
```bash
sudo apt-get install meson libgtk-3-dev libgranite-dev libsoup2.4-dev libcairo2-dev libglib2.0-dev ninja-build valac
```

### Compiling
```bash
meson build
cd build
ninja
```

### Installing
This is a reference implementation and is not designed to be installed.
However, if you do want to install it, simply run `sudo ninja install`

### Running
#### Client
`./open-fax-format-client`

#### Server
`./open-fax-format-server`
