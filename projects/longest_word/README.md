# Project - Longest Word

## Part I

In this game, two players compete to find the longest word using randomly drawn letters (consonants and vowels).

## Game principle 


- The two players take turns to choose the number of vowels they wish to have in the letter draw.

- 10 letters are then drawn randomly.

- The goal is then to find the longest word possible using the drawn letters.
  

#### Example 1

- RANDOMLY DRAWN LETTERS (Consonants & Vowels)

  - | **```C```** | **```O```** | **```E```** | **```T```** | **```G```** | **```O```** **```L```** | **```Y```** | **```H```** | **```N```** |

- LONGEST WORD(s) (Displaying one word)

  - | **```TECHNOLOGY```** | 10-Letter Word

### Example 2

- RANDOMLY DRAWN LETTERS (Consonants & Vowels)

  - | **```I```** | **```M```** | **```A```** | **```H```** | **```G```** | **```O```** **```T```** | **```T```** | **```L```** | **```R```** |

- LONGEST WORD(s) (Displaying one word)

  - | **```ALGORITHM```** | 9-Letter Word

## Assigned work

Starting from a randomly drawn string of 10 letters (called ```drawn_letters```), we seek to find all possible combinations (strings) of 10, then of 9, 8, 7, 6, 5, 4, 3, and finally, 2 letters that can be obtained using the letters in the string ```drawn_letters```.

For example, with a string of 3 letters ```"ABC"```, we seek to obtain the following combinations of 3 and 2 letters:

- ABC, ACB, BAC, BCA, CAB, CBA 
- AB, BA, AC, CA, BC, CB

## Steps to follow

- A string is in minimal alphabetical order if its letters satisfy the relationship: ```s[i] <= s[i+1]```
    
    For instance, the string ```"ABC"``` is in minimal alphabetical order.

- A string is in maximal alphabetical order if its letters satisfy the relationship: ```s[i] >= s[i+1]```
  
    For example, ```"CBA"``` is in maximal alphabetical order.

- Consider the following procedure:

  1) Starting from a given string, find the largest terminal substring that is in maximal order. Let ```i``` be the index of the letter that is to the left of this substring.

  2) Find in the terminal substring located to the right of the ```ith``` letter, the closest to this ```ith``` letter among those which are superior to it. Let ```j``` be its index.

  3) Swap the ```ith``` letter and the ```jth``` letter.

  4) Rearrange the substring to the right of the ```ith``` letter so that it is in minimal order.

    - You have to start with a string in minimal order. 

    - We stop when we obtain a string in maximal order.

**Note:** In the second part of the project, the aim is to integrate the search in a dictionary (planar tree) to find the longest word (or all the words of n letters).