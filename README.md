# HEALTHY MENU RECOMMENDER EASYX

## Install <graphics.h> on Linux

### Installation procedures
[Reference](https://stackoverflow.com/questions/67636061/unable-to-install-libgraph-in-linux-ubuntu-20-04)

```
$ sudo apt-get install libsdl-image1.2 libsdl-image1.2-dev guile-2.2 guile-2.2-dev 
$ wget http://download.savannah.gnu.org/releases/libgraph/libgraph-1.0.2.tar.gz
$ tar -xzvf libgraph-1.0.2.tar.gz
$ cd libgraph-1.0.2
$ CPPFLAGS="$CPPFLAGS $(pkg-config --cflags-only-I guile-2.2) -fcommon" \
CFLAGS="$CFLAGS $(pkg-config --cflags-only-other guile-2.2) -fcommon" \
LDFLAGS="$LDFLAGS $(pkg-config --libs guile-2.2)" \
./configure
$ make && sudo make install
$ sudo cp /usr/local/lib/libgraph.* /usr/lib
```

### Test of the setup

```
$ g++ -o filename filename.cpp -lgraph
$ ./filename
```

## Install EasyX on Linux
[GUN/Linux 下使用 EasyX](https://www.cnblogs.com/aaroncoding/p/17116879.html)


## Enable database development (MySQL)
```
$ sudo apt-get install libmysqlclient-dev
```

https://stackoverflow.com/questions/67949563/no-sys-bsdtypes-h-when-trying-to-compile-a-windows-project-with-mingw-on-linux
- [how to use <Windows.h> c++](https://www.linux.org/threads/how-to-use-windows-h-c.28353/)

x86_64-w64-mingw32-g++ Hello.cpp -o hello64.exe
wine64 hello64.exe
