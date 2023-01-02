ALIDOR Lilou ; COUARD Théo

# Install dependencies

* cmake (at least version 3.15)
  - ** Linux ** : sudo apt install cmake
  - ** Mac ** : brew install cmake
  - ** Windows ** : https://cmake.org/install
* Doxygen
  - ** Linux ** : sudo apt install doxygen
  - ** Mac ** : brew install doxygen
  - ** Windows ** : https://www.doxygen.nl/manual/install.html

# Usage

## command line
To compile a project, first :
```shell
cd projectDirectory
mkdir build
cd build
cmake ..
make
```
Then each time you compile, from the same directory
```shell
make
```
If you add some new files and / or edit the *CMakeList.txt*, redo : 
```shell
cmake ..
make
```
Optional : if you want to install a lib
```shell
sudo make install
```
Optional : if you want to generate the doc
```shell
make html
```

