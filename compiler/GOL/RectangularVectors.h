//----------------------------------------------------------------------------------------
//	Copyright © 2007 - 2017 Tangible Software Solutions Inc.
//	This class can be used by anyone provided that the copyright notice remains intact.
//
//	This class includes methods to convert multidimensional arrays to C++ vectors.
//----------------------------------------------------------------------------------------
class RectangularVectors
{
public:
    static std::vector<std::vector<bool>> ReturnRectangularBoolVector(int size1, int size2)
    {
        std::vector<std::vector<bool>> newVector(size1);
        for (int vector1 = 0; vector1 < size1; vector1++)
        {
            newVector[vector1] = std::vector<bool>(size2);
        }

        return newVector;
    }
};