```
$ arm-none-eabi-gcc -v
Using built-in specs.
COLLECT_GCC=C:\MaximSDK\Tools\GNUTools\10.3\bin\arm-none-eabi-gcc.exe
COLLECT_LTO_WRAPPER=c:/maximsdk/tools/gnutools/10.3/bin/../lib/gcc/arm-none-eabi/10.3.1/lto-wrapper.exe
Target: arm-none-eabi
Configured with: /mnt/workspace/workspace/GCC-10-pipeline/jenkins-GCC-10-pipeline-338_20211018_1634516203/src/gcc/configure --build=x86_64-linux-gnu --host=i686-w64-mingw32 --target=arm-none-eabi --prefix=/mnt/workspace/workspace/GCC-10-pipeline/jenkins-GCC-10-pipeline-338_20211018_1634516203/install-mingw --libexecdir=/mnt/workspace/workspace/GCC-10-pipeline/jenkins-GCC-10-pipeline-338_20211018_1634516203/install-mingw/lib --infodir=/mnt/workspace/workspace/GCC-10-pipeline/jenkins-GCC-10-pipeline-338_20211018_1634516203/install-mingw/share/doc/gcc-arm-none-eabi/info --mandir=/mnt/workspace/workspace/GCC-10-pipeline/jenkins-GCC-10-pipeline-338_20211018_1634516203/install-mingw/share/doc/gcc-arm-none-eabi/man --htmldir=/mnt/workspace/workspace/GCC-10-pipeline/jenkins-GCC-10-pipeline-338_20211018_1634516203/install-mingw/share/doc/gcc-arm-none-eabi/html --pdfdir=/mnt/workspace/workspace/GCC-10-pipeline/jenkins-GCC-10-pipeline-338_20211018_1634516203/install-mingw/share/doc/gcc-arm-none-eabi/pdf --enable-languages=c,c++ --enable-mingw-wildcard --disable-decimal-float --disable-libffi --disable-libgomp --disable-libmudflap --disable-libquadmath --disable-libssp --disable-libstdcxx-pch --disable-nls --disable-shared --disable-threads --disable-tls --with-gnu-as --with-gnu-ld --with-headers=yes --with-newlib --with-python-dir=share/gcc-arm-none-eabi --with-sysroot=/mnt/workspace/workspace/GCC-10-pipeline/jenkins-GCC-10-pipeline-338_20211018_1634516203/install-mingw/arm-none-eabi --with-libiconv-prefix=/mnt/workspace/workspace/GCC-10-pipeline/jenkins-GCC-10-pipeline-338_20211018_1634516203/build-mingw/host-libs/usr --with-gmp=/mnt/workspace/workspace/GCC-10-pipeline/jenkins-GCC-10-pipeline-338_20211018_1634516203/build-mingw/host-libs/usr --with-mpfr=/mnt/workspace/workspace/GCC-10-pipeline/jenkins-GCC-10-pipeline-338_20211018_1634516203/build-mingw/host-libs/usr --with-mpc=/mnt/workspace/workspace/GCC-10-pipeline/jenkins-GCC-10-pipeline-338_20211018_1634516203/build-mingw/host-libs/usr --with-isl=/mnt/workspace/workspace/GCC-10-pipeline/jenkins-GCC-10-pipeline-338_20211018_1634516203/build-mingw/host-libs/usr --with-libelf=/mnt/workspace/workspace/GCC-10-pipeline/jenkins-GCC-10-pipeline-338_20211018_1634516203/build-mingw/host-libs/usr --with-host-libstdcxx='-static-libgcc -Wl,-Bstatic,-lstdc++,-Bdynamic -lm' --with-pkgversion='GNU Arm Embedded Toolchain 10.3-2021.10' --with-multilib-list=rmprofile,aprofile
Thread model: single
Supported LTO compression algorithms: zlib
gcc version 10.3.1 20210824 (release) (GNU Arm Embedded Toolchain 10.3-2021.10)
 
$ arm-none-eabi-gdb -v
GNU gdb (GNU Arm Embedded Toolchain 10.3-2021.10) 10.2.90.20210621-git
Copyright (C) 2021 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
 
$ make -v
GNU Make 4.3
Built for x86_64-pc-msys
Copyright (C) 1988-2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
 
$ openocd -v
Open On-Chip Debugger 0.11.0+dev-g56a818e4c (2023-06-28-22:13)
Licensed under GNU GPL v2
For bug reports, read
        http://openocd.org/doc/doxygen/bugs.html
```