#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/liloualidor/Documents/IMAC/annee_2/C++/S3/Projet_prog_S3/build-xcode
  make -f /Users/liloualidor/Documents/IMAC/annee_2/C++/S3/Projet_prog_S3/build-xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/liloualidor/Documents/IMAC/annee_2/C++/S3/Projet_prog_S3/build-xcode
  make -f /Users/liloualidor/Documents/IMAC/annee_2/C++/S3/Projet_prog_S3/build-xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/liloualidor/Documents/IMAC/annee_2/C++/S3/Projet_prog_S3/build-xcode
  make -f /Users/liloualidor/Documents/IMAC/annee_2/C++/S3/Projet_prog_S3/build-xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/liloualidor/Documents/IMAC/annee_2/C++/S3/Projet_prog_S3/build-xcode
  make -f /Users/liloualidor/Documents/IMAC/annee_2/C++/S3/Projet_prog_S3/build-xcode/CMakeScripts/ReRunCMake.make
fi
