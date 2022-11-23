#ifndef __RATIO__HPP
#define __RATIO__HPP

#include <iostream>
#include <math.h>

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
/// \subsection installSec Install with cmake (C++17) (Linux / Mac)
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

/// \brief return the sign of the number
/// \return 1 if positive or equal to 0, -1 otherwise
inline int sign(const float nb) {return (nb >= 0) - (nb < 0);}

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
    /// \todo create a limit to not exceed the bit size of the number type and avoid infinite loop
    /// \todo create an epsylon of difference between the actual number and the rational
    static Ratio convertFloatToRatio(const float & number, unsigned nb_iter = 10);
    static Ratio sqrt(const Ratio &r);

    /// \brief convert a rational to a real
    /// \param  number: the rational to be converted
    /// \return the real number
    float convertRatioToFloat()const;
    
    /// \brief return the sign of the rational
    /// \return 1 if positive or equal to 0, -1 otherwise
    inline int numSign() const {return sign(mNum);}
    
    /// \brief simplify a rational
    /// \return the modified number
    Ratio& simplify();
    
    Ratio operator+(const Ratio &r) const;
    
    Ratio invert() const;  
    
};

#endif



