// CounterIt.hpp
//
// Author: Thomas C. Etavard (https://github.com/etavardt)
// Date: 02/07/2023
// 
// GitHub link: https://github.com/etavardt/CounterIt
//
// An iterator that counts instead of iterating over objects.
//
// Usage:
//     // One Example:
//     #include <execution>
//     #include "CounterIt.hpp"
//     ...
//     Kewl::Counter count( startValue, endValue );
//     std::for_each(std::execution::par, count.begin(), count.end(), []( const int& i ) { std::cout << " " << i; });
// 
// This could return an out of order count since it is a for_each loop where the tasks are ran in parrallel asynchronous
// but each task needs to know the value(i in this case) it will work with. Do not use this for_each if you need the 
// order to be synchronous.
//

#pragma once

#include <iterator>
#include <cassert>

namespace Kewl {

    class Counter {
    private:
        class iterator {
            long m_Start = 0;
            long m_End = 0;
            long m_Num = 0;
            bool m_Rev = false;
        public:
            using iterator_category = std::forward_iterator_tag;
            using difference_type   = std::ptrdiff_t;
            using value_type        = long;
            using pointer           = const long*;
            using reference         = long;

            iterator() = default;
            explicit iterator( value_type _num, value_type _start, value_type _end, bool _rev = 0 ) : m_Num( _num ), m_Start( _start ), m_End( _end ), m_Rev( _rev ) {}

            iterator& operator++() {
                assert( m_Num >= std::min( m_Start, m_End ) && "Out of range: less than the min bound!" );
                assert( m_Num <= std::max( m_Start, m_End ) && "Out of range: greater than the max bound!" );
                m_Num = m_Rev ? m_Num - 1 : m_Num + 1;
                return *this;
            }
            iterator operator++( int ) { iterator retval = *this; ++(*this); return retval; }
            bool operator==( iterator other ) const { return m_Num == other.m_Num; }
            bool operator!=( iterator other ) const { return !(*this == other); }
            reference operator*() const { return m_Num; }
        };

        bool m_Rev = false;
        long m_Start = 0;
        long m_End = 0;
    public:
        using Iterator = iterator;
        Iterator begin() { return Iterator( m_Start, m_Start, m_End, m_Rev ); }
        Iterator first() { return Iterator( m_Start, m_Start, m_End, m_Rev ); }
        Iterator last() { return Iterator( m_End, m_Start, m_End, m_Rev ); }
        Iterator end() { return Iterator( (m_Rev ? m_End - 1 : m_End + 1), m_Start, m_End, m_Rev ); }
        Iterator rbegin() { return Iterator( m_End, m_End, m_Start, !m_Rev ); }
        Iterator rfirst() { return Iterator( m_End, m_End, m_Start, !m_Rev ); }
        Iterator rlast() { return Iterator( m_Start, m_Start, m_End, !m_Rev ); }
        Iterator rend() { return Iterator( (!m_Rev ? m_Start - 1 : m_Start + 1), m_Start, m_End, !m_Rev ); }

        Counter() = delete;
        Counter( long _end ) :
            m_Start( 0 ),
            m_End( _end ),
            m_Rev( 0 > _end ) {}
        Counter( long _start, long _end ) :
            m_Start( _start ),
            m_End( _end ),
            m_Rev( _start > _end ) {}
        ~Counter() {};
        Counter( const Counter& ) = delete;
        Counter( const Counter&& ) = delete;
        const Counter& operator=( const Counter& ) = delete;
        const Counter& operator=( const Counter&& ) = delete;
    };
} // namespace Kewl
