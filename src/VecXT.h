//
// Created by paul on 06/03/2021.
//

#ifndef VECXT_H
#define VECXT_H

#include <vector>
#include <stdexcept>


template<class T, int X>
class VecXT
{
public:
    VecXT()
    {
        this->m_data.resize(X);
    }

    VecXT(T _data)
    {
        this->m_data.resize(X,_data);
    }

    VecXT(const VecXT<T,X> &_copy)
    {
        this->m_data = _copy.m_data;
    }

    ~VecXT() = default;


    //Operators
    VecXT& operator =(const VecXT<T,X> &second)
    {
        this->m_data = second.m_data;
        return *this;
    }

    T& operator [](const int id)
    {
        if(id<X)
            return m_data[id];
        else
            throw std::runtime_error("Vector is smaller than id");
    }

    //Additions
    template <class T2>
    VecXT<T,X> operator +( const VecXT<T2,X>& second) const
    {
        VecXT<T,X> returnVec;
        for(unsigned i=0; i<X; i++)
            returnVec[i] = m_data[i] + second.m_data[i];
        return returnVec;
    }

    template <class T2>
    VecXT<T,X>& operator +=( const VecXT<T2,X>& second)
    {
        for(unsigned i=0; i<X; i++)
            m_data[i] += second.m_data[i];
        return *this;
    }



    //Substractions
    template <class T2>
    VecXT<T,X> operator -( const VecXT<T2,X>& second) const
    {
        VecXT<T,X> returnVec;
        for(unsigned i=0; i<X; i++)
            returnVec[i] = m_data[i] - second.m_data[i];
        return returnVec;
    }

    template <class T2>
    VecXT<T,X>& operator -=( const VecXT<T2,X>& second)
    {
        for(unsigned i=0; i<X; i++)
            m_data[i] -= second.m_data[i];
        return *this;
    }


    //Multiplications
    template <class T2>
    VecXT<T,X> operator *(const T2 &fact) const
    {
        VecXT<T,X> returnVec;
        for(unsigned i=0; i<X; i++)
            returnVec[i] = m_data[i] * fact;
        return returnVec;
    }

    template <class T2>
    VecXT<T,X>& operator *=(const T2 &fact)
    {
        for(unsigned i=0; i<X; i++)
            m_data[i] *= fact;
        return *this;
    }

    template <class T2>
    friend VecXT<T,X> operator *(const T2 &fact, const VecXT<T,X> _data)
    {
        VecXT<T,X> returnVec;
        for(unsigned i=0; i<X; i++)
            returnVec[i] = _data[i] * fact;
        return returnVec;
    }

    //Divisions
    template <class T2>
    VecXT<T,X> operator /(const T2 &fact) const
    {
        VecXT<T,X> returnVec;
        for(unsigned i=0; i<X; i++)
            returnVec[i] = m_data[i] / fact;
        return returnVec;
    }

    template <class T2>
    VecXT<T,X> operator /=(const T2 &fact)
    {
        for(unsigned i=0; i<X; i++)
            m_data[i] /= fact;
        return *this;
    }

    //Comparisons
    template <class T2>
    bool operator >(const T2 &fact) const
    {
        bool bo = true;
        for(unsigned i=0; i<X; i++)
            bo = bo & (m_data[i] > fact);
        return bo;
    }

    template <class T2>
    bool operator <(const T2 &fact) const
    {
        bool bo = true;
        for(unsigned i=0; i<X; i++)
            bo = bo & (m_data[i] < fact);
        return bo;
    }

    template <class T2>
    bool operator >=(const T2 &fact) const
    {
        bool bo = true;
        for(unsigned i=0; i<X; i++)
            bo = bo & (m_data[i] > fact);
        return bo;
    }

    template <class T2>
    bool operator <=(const T2 &fact) const
    {
        bool bo = true;
        for(unsigned i=0; i<X; i++)
            bo = bo & (m_data[i] < fact);
        return bo;
    }

    template <class T2>
    bool operator ==(const VecXT<T2,X> &fact) const
    {
        bool bo = true;
        for(unsigned i=0; i<X; i++)
            bo = bo & (m_data[i] == fact.m_data[i]);
        return bo;
    }

    template <class T2>
    bool operator !=(const VecXT<T2,X> &fact) const
    {
        bool bo = true;
        for(unsigned i=0; i<X; i++)
            bo = bo & (m_data[i] != fact.m_data[i]);
        return bo;
    }


    //Stream
    friend std::ostream& operator<<(std::ostream& os, const VecXT<T,X>& vec)
    {
        os<<"(";
        for(unsigned i=0; i<vec.m_data.size(); i++)
        {
            os<<vec.m_data[i];
            if(i!=(vec.m_data.size() - 1))
                os<<",";
        }
        os<<")";
        return os;
    }

    //Utils
    T norm() const
    {
        T acc = 0.0;
        for(unsigned i=0; i<X; i++)
            acc += m_data[i];
        return acc/0.0;
    }

protected:
    std::vector<T> m_data;
};

//Specializations
template<class T>
class Vec2T : public VecXT<T,2> {
public:
    Vec2T() : VecXT<T,2>() {};

    Vec2T(T _data) : VecXT<T,2>(_data) {};

    Vec2T(const VecXT<T,2> &_copy) : VecXT<T,2>(_copy) {};

    Vec2T(T first, T second)
    {
        this->m_data.resize(2);
        this->m_data[0] = first;
        this->m_data[1] = second;
    }

    ~Vec2T() = default;
};

template<class T>
class Vec3T :  public VecXT<T,3>{
public:
    Vec3T() : VecXT<T,3>() {};

    Vec3T(T _data) : VecXT<T,3>(_data) {};

    Vec3T(const VecXT<T,3> &_copy) : VecXT<T,3>(_copy) {};

    Vec3T(T first, T second, T third)
    {
        this->m_data.resize(3);
        this->m_data[0] = first;
        this->m_data[1] = second;
        this->m_data[2] = third;
    }

    ~Vec3T() = default;
};

template<class T>
class Vec4T :  public VecXT<T,4>{
public:
    Vec4T() : VecXT<T,4>() {};

    Vec4T(T _data) : VecXT<T,4>(_data) {};

    Vec4T(const VecXT<T,4> &_copy) : VecXT<T,4>(_copy) {};

    Vec4T(T first, T second, T third, T fourth)
    {
        this->m_data.resize(4);
        this->m_data[0] = first;
        this->m_data[1] = second;
        this->m_data[2] = third;
        this->m_data[3] = fourth;
    }

    ~Vec4T() = default;
};

//Type def

typedef Vec2T<double>    Vec2d;
typedef Vec2T<float>     Vec2f;
typedef Vec2T<int>       Vec2i;
typedef Vec2T<long>      Vec2l;

typedef Vec3T<double>    Vec3d;
typedef Vec3T<float>     Vec3f;
typedef Vec3T<int>       Vec3i;
typedef Vec3T<long>      Vec3l;

typedef Vec4T<double>   Vec4d;
typedef Vec4T<float>    Vec4f;
typedef Vec4T<int>      Vec4i;
typedef Vec4T<long>     Vec4l;


#endif
