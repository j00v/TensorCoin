
Debian
====================
This directory contains files used to package tensorcoind/tensorcoin-qt
for Debian-based Linux systems. If you compile tensorcoind/tensorcoin-qt yourself, there are some useful files here.

## tensorcoin: URI support ##


tensorcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install tensorcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your tensorcoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/tensorcoin128.png` to `/usr/share/pixmaps`

tensorcoin-qt.protocol (KDE)

