#ifndef __RATIO__HPP
#define __RATIO__HPP

#include <iostream>

// Doxygen menu
/// \version 0.1
/// \mainpage
/// \image html myImage.jpg
/// \tableofcontents
/// \section instroduction_sec What for?
/// Ratio is a moderatly cool tool.
/// \section installBigSec How to install ?
/// \subsection dependencies_sec Dependecies
/// \li nothing
/// \li Doxygen (if you want the documentation)
/// \subsection installSec Install with cmake (Linux / Mac)
/// \li go to main dir
/// \li mkdir build
/// \li cd build
/// \li cmake ..
/// \li make
/// \subsection XCodeSec Install for XCode (Mac)
/// \li go to main dir
/// \li mkdir build-xcode
/// \li cd build-xcode
/// \li cmake .. -GXcode
/// \subsection docSec Doxygen Documentation (Linux / Mac)
/// \li need Doxygen installed: make html
/// \li The documentation is located in :
/// 	- [path to build]/doc/doc-doxygen/html/index.html or 
/// 	- or [path to build]/INTERFACE/doc/doc-doxygen/html/index.html



/// \class Ratio
/// \brief class defining a rational for algebra operations.
class Ratio {
    
private:
    int mNum; /*!< numerator component */
    int mDenom; /*!< denominator component */
    
public:
    
    /// \brief constructor from rational
    /// \param num : the numerator component of the rational
    /// \param denom : the denominator component of the rational
    Ratio(const int & num = 0, const int & denom = 1);
    
    /// \brief constructor from float
    /// \param number : the number to be converted into rational
    Ratio(const float & number);
    
    /// \brief copy-constructor
    /// \param r : the source rational to be copied
    Ratio(const Ratio & r);
    
    /// \brief destructor
    ~Ratio() = default;
    
    //Operators
    Ratio operator+(const Ratio &r);
    Ratio operator-(const Ratio &r);
    Ratio operator*(const Ratio &r);
    Ratio operator*(const float &f);
    Ratio operator/(const Ratio &r);
    Ratio operator-();
    friend std::ostream& operator<< (std::ostream& stream, const Ratio& ratio);

    /// \brief operator to access to the ist element of a vector
    /// \param  i: index of the targeted vector component
    /// \return vector[i]
    /// \bug
    /// \todo
    /// \test
    //exemple de doc doxygen À ENLEVER
    
public:
    
    /// \brief convert a real to a rational
    /// \param  number: the real to be converted
    /// \param  nb_iter: iterations of the conversion
    /// \return the rational number
    Ratio convertFloatToRatio(const float & number, const unsigned & nb_iter = 10);
    
    /// \brief convert a rational to a real
    /// \param  number: the rational to be converted
    /// \return the real number
    float convertRatioToFloat(const Ratio & number);
    
};

inline int sign(const int nb) {return (nb >= 0) - (nb < 0);}

#endif



