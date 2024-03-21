// "I pledge my honor that I have abided by the Stevens Honor System" - Justin Ferber

#ifndef NATURALMERGESORTER_H
#define NATURALMERGESORTER_H

class NaturalMergeSorter {
public:
    virtual int GetSortedRunLength(int* array, int arrayLength, int startIndex) {
        int count = 0, left = startIndex, right = startIndex + 1;
        if (startIndex < 0 || startIndex > arrayLength - 1) {
            return count;
        }        
        while (array[left] <= array[right] && right < arrayLength) {
            count++;
            left++;
            right++;
        }
        return count + 1;
    }
    virtual void NaturalMergeSort(int* array, int arrayLength) {
        int i = 0;
        while (i < arrayLength) {
            int firstLength = GetSortedRunLength(array, arrayLength, i);
            if (firstLength == arrayLength) {
                return;
            }
            if (firstLength + i == arrayLength) {
                i = 0;
                continue;
            }
            int secondLength = GetSortedRunLength(array, arrayLength, firstLength + i);
            Merge(array, i, firstLength + i - 1, i + secondLength + firstLength - 1);
            if (i + secondLength + firstLength != arrayLength) {
                i += firstLength + secondLength;
            } else {
                i = 0;
            }
        }
    }
    
    virtual void Merge(int* numbers, int leftFirst, int leftLast, int rightLast) {
        int mergedSize = rightLast - leftFirst + 1;
        int* mergedNumbers = new int[mergedSize];
        int mergePos = 0;
        int leftPos = leftFirst;
        int rightPos = leftLast + 1;
        
        // Add smallest element from left or right partition to merged numbers
        while (leftPos <= leftLast && rightPos <= rightLast) {
            if (numbers[leftPos] <= numbers[rightPos]) {
                mergedNumbers[mergePos] = numbers[leftPos];
                leftPos++;
            } else {
                mergedNumbers[mergePos] = numbers[rightPos];
                rightPos++;
            }
            mergePos++;
        }
        
        // If left partition isn't empty, add remaining elements to mergedNumbers
        while (leftPos <= leftLast) {
            mergedNumbers[mergePos] = numbers[leftPos];
            leftPos++;
            mergePos++;
        }
        
        // If right partition isn't empty, add remaining elements to mergedNumbers
        while (rightPos <= rightLast) {
            mergedNumbers[mergePos] = numbers[rightPos];
            rightPos++;
            mergePos++;
        }

        // Copy merged numbers back to numbers
        for (mergePos = 0; mergePos < mergedSize; mergePos++) {
            numbers[leftFirst + mergePos] = mergedNumbers[mergePos];
        }
        
        // Free temporary array
        delete[] mergedNumbers;
    }
};

#endif
