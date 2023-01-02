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
template<typename U>
inline int sign(const U nb) {return (nb >= 0) - (nb < 0);}

/// \class Ratio
/// \brief class defining a rational for algebra operations.
template <typename T>
class Ratio {
    
private:
    T mNum; /*!< numerator component */
    T mDenom; /*!< denominator component */
    int mSign;
    
public:
    
    //Constructors
    
    /// \brief Constructor from rational
    /// \param num : The numerator component of the rational
    /// \param denom : The denominator component of the rational
    Ratio(const T & num = 0, const T & denom = 1, const int & sign = 0);
    
    /// \brief Constructor from float
    /// \param number : The number to be converted into rational
    Ratio(const double & number);
    
    /// \brief Copy-constructor
    /// \param r : The source rational to be copied
    Ratio(const Ratio & r, const int & sign = 0);
    
    /// \brief Destructor
    ~Ratio() = default;
    
public:
    //Getters
    
    /// \brief Returns the numerator value
    inline T getNum() const { return mNum;};
    
    /// \brief Returns the denominator value
    inline T getDenom() const { return mDenom;};
    
public:
    
    //Operators//
    
    //Ratio + Ratio
    Ratio operator+(const Ratio &r)const;
    
    //Ratio + double
    Ratio operator+(const double &f)const;
    
    //float + Ratio
    template<typename U>
    friend Ratio<U> operator+(const double &f, const Ratio<U> &r);
    
    //Ratio - Ratio
    Ratio operator-(const Ratio &r)const;
    
    //Ratio - float
    Ratio operator-(const double &f)const;
    
    //float - Ratio
    template<typename U>
    friend Ratio<U> operator-(const double &f, const Ratio<U> &r);
    
    //-Ratio
    Ratio operator-()const;
    
    //Ratio % Ratio
    Ratio operator%(const Ratio &r)const;
    
    //Ratio % float
    Ratio operator%(const double &f)const;
    
    //float % Ratio
    template<typename U>
    friend Ratio<U> operator%(const double &f, const Ratio<U> &r);

    //Ratio * Ratio
    Ratio operator*(const Ratio &r)const;

    //ratio * float-
    Ratio operator*(const double &f)const;

    //float * Ratio
    template<typename U>
    friend Ratio<U> operator*(const double &f, const Ratio<U> &r);

    //Ratio / Ratio
    Ratio operator/(const Ratio &r)const;

    //ratio / float
    Ratio operator/(const double &f)const;

    //float / Ratio
    template<typename U>
    friend Ratio<U> operator/(const double &f, const Ratio<U> &r);


    //comparing Ratio with Ratio//
    bool operator==(const Ratio &r)const;
    bool operator!=(const Ratio &r)const;
    bool operator<(const Ratio &r)const;
    bool operator>(const Ratio &r)const;
    bool operator<=(const Ratio &r)const;
    bool operator>=(const Ratio &r)const;

    //comparing Ratio with float//
    bool operator==(const double &f)const;
    bool operator!=(const double &f)const;
    bool operator<(const double &f)const;
    bool operator>(const double &f)const;
    bool operator<=(const double &f)const;
    bool operator>=(const double &f)const;


    //comparing float with Ratio//
    template<typename U>
    friend bool operator==(const double &f, const Ratio<U> &r);
    template<typename U>
    friend bool operator!=(const double &f, const Ratio<U> &r);
    template<typename U>
    friend bool operator<(const double &f, const Ratio<U> &r);
    template<typename U>
    friend bool operator>(const double &f, const Ratio<U> &r);
    template<typename U>
    friend bool operator<=(const double &f, const Ratio<U> &r);
    template<typename U>
    friend bool operator>=(const double &f, const Ratio<U> &r);

    template<typename U>
    friend std::ostream& operator<< (std::ostream& stream, const Ratio<U>& ratio);
    
public:
    
    //Various other functions
    
    /// \brief Compute the square root of rational
    /// \param  r: The rational to be squared
    /// \return Returns the square root of a rational
    static Ratio sqrt(const Ratio &r);

    /// \brief Compute exponential function
    /// \param  r: The rational to be computed in the exponential function
    /// \return Returns the base-e exponential function of r
    static Ratio exp(const Ratio &r);

    /// \brief Compute cosinus function in degrees
    /// \param  r: The rational to be computed in the cosinus function
    /// \return Returns the cosinus of the rational in degrees
    static Ratio cos(const Ratio &r);

    /// \brief Compute arc cosinus function in degrees
    /// \param  r: The rational to be computed in the arc cosinus function
    /// \return Returns the angle in degrees of the rational cosinus
    static Ratio acos(const Ratio &r);

    /// \brief Compute sinus function in degrees
    /// \param  r: The rational to be computed in the sinus function
    /// \return Returns the sinus of the rational in degrees
    static Ratio sin(const Ratio &r);
    
    /// \brief Compute arc sinus function in degrees
    /// \param  r: The rational to be computed in the arc sinus function
    /// \return Returns the angle of the rational sinus
    static Ratio asin(const Ratio &r);
    
    /// \brief Compute tangent function in degrees
    /// \param  r: The rational to be computed in the tangent function
    /// \return Returns the tangent of the rational in degrees
    static Ratio tan(const Ratio &r);

    /// \brief Compute arc tangent function in degrees
    /// \param  r: The rational to be computed in the arc tangent function
    /// \return Returns the angle of the rational tangent
    static Ratio atan(const Ratio &r);

    /// \brief Compute absolute value of a rational
    /// \param  r: The rational to be computed in the absolute value function
    /// \return Returns the absolute value of the rational number
    static Ratio abs(const Ratio &r);

    /// \brief Compute round down value of a rational
    /// \param  r: The rational to round down
    /// \return Returns the value of r rounded downward
    static Ratio floor(const Ratio &r);

    /// \brief Searches the greatest common rational divisor between two rational numbers
    /// \param  r1: First rational number
    /// \param  r2: Second rational number
    /// \return If both r1 and r2 are zero, returns zero. If both r1 and r2 tend towards Inf., returns Inf.
    ///         Otherwise, returns the greatest common rational divisor of |r1| and |r2|
    static Ratio gcrd(const Ratio &r1, const Ratio &r2);

    /// \brief Compute the natural logarithm of a rational number
    /// \param  r: The rational number whose logarithm is calculated
    /// \return Returns the natural logarithm of r
    static Ratio log(const Ratio &r);

    /// \brief Raise the given rational number to the power exponent
    /// \param  r: The rational number to raise
    /// \param  exponent: The power exponent
    /// \return Returns r raised to the power exponent
    static Ratio pow(const Ratio &r, const long &exponent);

    /// \brief Indicates that a rational equals to 0
    /// \return Returns a null rational number(0/1)
    static Ratio Zero();

    /// \brief Indicates that a rational is tending towards infinity
    /// \return Returns a rational number tending towards infinity (1/0)
    static Ratio Infinite();

    /// \brief Convert a real to a rational
    /// \param  number: The real to be converted
    /// \param  nb_iter: Iterations of the conversion
    /// \return Returns the corresponding rational number
    static Ratio convertFloatToRatio(const double & number, unsigned nb_iter = 15);

    /// \brief Convert a rational to a real
    /// \param  number: The rational to be converted
    /// \return Returns the corresponding real number
    auto convertRatioToFloat()const;
    
    /// \brief Returns the sign of the rational
    /// \return Returns 1 if positive or equal to 0, -1 otherwise
    inline int signRatio() const {return mSign;}
    
    /// \brief Simplify a rational
    /// \return Returns the number, simplified
    Ratio& simplify();

    /// \brief Inverse a rational
    /// \return Returns the inversed rational
    Ratio invert() const;  
    
};

#endif



