# SedgewickAlgorithmsInC
A collection of exercises to Sedgewicks Algorithms in C, Third Edition.

## Motivation

These solutions have been written for my own learning and interest. They
have been made public in the case that others may find them useful.

Additionally they have been written with the C23 standard in mind to
explore the new standard, though the should not heavily rely on the
features provided.

## Structure

This code base has been broken down by Chapter, and further subdivided
into 
1. Examples - Code fragments provided by the author
2. Exercises - Solutions to Exercises

Each Chapter has a markdown file `index.md` to describe the exercises
contained within. This file may also contain solutions to mathematical
exercises. Where useful each chapter may be further subdivided
into different sections such as `Chapter 3`, where `Arrays`, `Linked Lists`
and `Strings` are treated as their own components.

### Contents

#### Fundamentals
1. [Chapter 1](./Chapter1/index.md) Introduction
2. [Chapter 2](./Chapter2/index.md) Principles of Algorithm Analysis
#### Data Structures
3. [Chapter 3](./Chapter3/index.md) Elementary Data Structures
4. [Chapter 4](./Chapter4/index.md) Abstract Data Types

## Portability

These programs have been compiled on Ubuntu LTS 24.04 using GCC 14. 

All programs have been compiled with the C23 standard and may make use of
some features unique to that standard. Most commonly this is through the
use of `nullptr` in place of `NULL` and the keywords `bool`, `false` and
`true` without the use of the header `stdbool.h`. Programs may require
modification to run on older standards.

