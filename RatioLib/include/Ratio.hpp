#ifndef __RATIO__HPP
#define __RATIO__HPP

#include <iostream>
#include <cmath>

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
    long mNum; /*!< numerator component */
    long mDenom; /*!< denominator component */
    
public:
    
    //Constructors
    
    /// \brief constructor from rational
    /// \param num : the numerator component of the rational
    /// \param denom : the denominator component of the rational
    Ratio(const long & num = 0, const long & denom = 1);
    
    /// \brief constructor from float
    /// \param number : the number to be converted into rational
    Ratio(const float & number);
    
    /// \brief copy-constructor
    /// \param r : the source rational to be copied
    Ratio(const Ratio & r);
    
    /// \brief destructor
    ~Ratio() = default;
    
public:
    //Getters
    
    /// \brief returns the numerator value
    inline long getNum() const { return mNum;};
    
    /// \brief returns the denominator value
    inline long getDenom() const { return mDenom;};
    
public:
    
    //Operators//
    
    Ratio operator+(const Ratio &r)const;
    Ratio operator-(const Ratio &r)const;
    Ratio operator-()const;
    Ratio operator%(const Ratio &r)const;

    //Ratio * Ratio
    Ratio operator*(const Ratio &r)const;

    //ratio * float
    Ratio operator*(const float &f)const;

    //float * Ratio
    friend Ratio operator*(const float &f, const Ratio &r);

    //Ratio / Ratio
    Ratio operator/(const Ratio &r)const;

    //ratio / float
    Ratio operator/(const float &f)const;

    //float / Ratio
    friend Ratio operator/(const float &f, const Ratio &r);


    //comparing Ratio with Ratio//
    bool operator==(const Ratio &r)const;
    bool operator!=(const Ratio &r)const;
    bool operator<(const Ratio &r)const;
    bool operator>(const Ratio &r)const;
    bool operator<=(const Ratio &r)const;
    bool operator>=(const Ratio &r)const;

    //comparing Ratio with float//
    bool operator==(const float &f)const;
    bool operator!=(const float &f)const;
    bool operator<(const float &f)const;
    bool operator>(const float &f)const;
    bool operator<=(const float &f)const;
    bool operator>=(const float &f)const;


    //comparing float with Ratio//
    friend bool operator==(const float &f, const Ratio &r);
    friend bool operator!=(const float &f, const Ratio &r);
    friend bool operator<(const float &f, const Ratio &r);
    friend bool operator>(const float &f, const Ratio &r);
    friend bool operator<=(const float &f, const Ratio &r);
    friend bool operator>=(const float &f, const Ratio &r);



    friend std::ostream& operator<< (std::ostream& stream, const Ratio& ratio);
    

    /// \brief operator to access to the ist element of a vector
    /// \param  i: index of the targeted vector component
    /// \return vector[i]
    /// \bug
    /// \todo
    /// \test
    //exemple de doc doxygen À ENLEVER
    
public:
    
    //Various other functions
    
    /// \brief Do the square root of rational
    /// \param  r: the rational to be squared
    /// \return the square root of a rational
    static Ratio sqrt(const Ratio &r);

    /// \brief Compute exponential function
    /// \param  r: the rational to be computed in the exponential function
    /// \return Returns the base-e exponential function of r
    static Ratio exp(const Ratio &r);

    static Ratio cos(Ratio &r);
    //cos
    //sin
    //tan
    //abs
    //ent
    //gcd
    //log
    //pow
    

    static Ratio Zero();
    static Ratio Infinite();

    /// \brief convert a real to a rational
    /// \param  number: the real to be converted
    /// \param  nb_iter: iterations of the conversion
    /// \return the rational number
    static Ratio convertFloatToRatio(const float & number, unsigned nb_iter = 15);

    /// \brief convert a rational to a real
    /// \param  number: the rational to be converted
    /// \return the real number
    float convertRatioToFloat()const;
    
    /// \brief return the sign of the rational
    /// \return 1 if positive or equal to 0, -1 otherwise
    inline int signRatio() const {return sign(mNum);}
    
    /// \brief simplify a rational
    /// \return the modified number
    Ratio& simplify();

    /// \brief invert a rational
    /// \return the inverted rational
    Ratio invert() const;  
    
};

#endif



