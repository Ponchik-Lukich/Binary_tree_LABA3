#ifndef LAB3_SET_H
#define LAB3_SET_H

#pragma once
#include <algorithm>
#include <cassert>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
#include "BinaryTree.h"

template <class T>
class Set
{
private:

    Tree<T>* set;

public:
    Set(){
        this->set = new Tree<T>();
    }
    Set(const T node)
    {
        this->set = new Tree<T>();
        this->set->insert_node(node);
    }


    ~Set() = default;

    void add(const T node)
    {
        if(this->exist(node) == true)
        {
            return;
        }
        this->set->add(node);
    }

    bool exist(const T node) const
    {
        return this->set->check_element(node);
    }

    void delete_el(const T node)
    {
        if(this->exist(node) == true)
        {
            this->set->delete_node(set->find_node(set->get_root(),node));
        }
    }

    void show() const
    {
        this->set->print_set();
    }

    bool check(const T& value)
    {
        return this->set->check_element(value);
    }


/*
  //Итератор временно удален
    Set<T> Union(Set<T> first, Set<T> second)
    {
        Set<T> union_set;
        for (auto el : first)
            union_set.add(el);
        for (auto el : second)
            if(!first.check(el))
                union_set.add(el);
        return union_set;
    }

    Set<T> Intersection(Set<T> first, Set<T> second)
    {
        Set<T> intersection_set;
        for (auto el : first)
            if (second.check(el))
                intersection_set.add(el);
        return intersection_set;
    }

    Set<T> Subtraction(Set<T> first,Set<T> second)
    {
        Set<T> subtraction;
        for (auto el : first)
            if (!second.check(el))
                subtraction.add(el);
        return subtraction;
    }

    Set<T> map(T func(T)) {
        Set<T> res;
        for (auto x : this->set) {
            res.add(func(x));
        }
        return res;
    }

    Set<T> where(bool func(T)) {
        auto res = new Set<T>();
        for (auto x : this->set)
            if (func(x)) {
                res->add(x);
            }
        return res;
    }


    T reduce(T func(T, T)) {
        return set->reduce(func);
    }

    bool check_subset(Set<T> child){
        Set<T> main = set;
        for (auto x : child) {
            if (!child.check(x)) return false;
        }
        return true;
    }

    bool check_equel(Set<T> second){
        Set<T> first = set;
        return first.check_subset(second);
    }
*/

};
#endif