# Mini Ludum Dare 53 Jam #

> The futur is now

Brainstorming, brainstorming...

# Compilation #

The project use CMake, see the CMake HOWTO for your OS and IDE.

## Linux ##

It is cleaner to build in a separate directory rather than the root directory.  It avoid to have a lot of junk files in the root directory.  In the following, this directory is called `build`.

First, create the build directory:
```sh
$ mkdir build && cd build
```

Once in the build directory, invoque `cmake`:
```sh
$ cmake ..
```

From now, there is no needs to invoke `cmake ..` again.  To build the project, just use `make`.
```sh
$ make
```

## Windows ##

*TODO*

# Authors #

* Brahim Berkati
* Jérémy Derdaele
* Timothée Vialatoux
