#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft
{
    /*
    **  The type T is enabled as member type enable_if::type if Cond is true.
    */
    template <bool Cond, class T = void>
    struct enable_if
    {
    };

    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    template <class T>
    struct is_integral
    {
        static const bool value = false;
    };
    template <>
    struct is_integral<bool>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<char>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<signed char>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<short int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<long int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<long long int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned char>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned short int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned long int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned long long int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<char16_t>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<char32_t>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<wchar_t>
    {
        static const bool value = true;
    };

    /*
    **  Test whether the elements in two ranges are equal.
    */
    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1,
               InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (!(*first1 == *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    template <class InputIterator1, class   InputIterator2, class BinaryPredicate>
    bool equal(InputIterator1 first1, InputIterator1 last1,
               InputIterator2 first2, BinaryPredicate pred)
    {
        while (first1 != last1)
        {
            if (!pred(*first1, *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    /*
    **  Returns true if the range [first1,last1) compares lexicographically 
    **  less than the range [first2,last2).
    */
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                 InputIterator2 first2, InputIterator2 last2)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || *first2 < *first1)
                return (false);
            else if (*first1 < *first2)
                return (true);
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }
    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                 InputIterator2 first2, InputIterator2 last2,
                                 Compare comp)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || comp(*first2, *first1))
                return (false);
            else if (comp(*first1, *first2))
                return (true);
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

    /*
    ** map utils
    */
    template <class T1, class T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        first_type first;
        second_type second;

        pair() : first(), second()
        {
        }
        template <class U, class V>
        pair(const pair<U, V> &pr) : first(pr.first), second(pr.second)
        {
        }
        pair(const first_type &a, const second_type &b) : first(a), second(b)
        {
        }
        pair &operator=(const pair &pr)
        {
            if (this != &pr)
            {
                this->first = pr.first;
                this->second = pr.second;
            }
            return (*this);
        }

        template <class _T1, class _T2>
        friend bool operator==(const pair<_T1, _T2> &lhs, const pair<_T1, _T2> &rhs);
        template <class _T1, class _T2>
        friend bool operator!=(const pair<_T1, _T2> &lhs, const pair<_T1, _T2> &rhs);
        template <class _T1, class _T2>
        friend bool operator<(const pair<_T1, _T2> &lhs, const pair<_T1, _T2> &rhs);
        template <class _T1, class _T2>
        friend bool operator<=(const pair<_T1, _T2> &lhs, const pair<_T1, _T2> &rhs);
        template <class _T1, class _T2>
        friend bool operator>(const pair<_T1, _T2> &lhs, const pair<_T1, _T2> &rhs);
        template <class _T1, class _T2>
        friend bool operator>=(const pair<_T1, _T2> &lhs, const pair<_T1, _T2> &rhs);
    };

    template <class T1, class T2>
    bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }

    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
    }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(lhs < rhs);
    }

    template <class T1, class T2>
    pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return (ft::pair<T1, T2>(x, y));
    };
}

#endif