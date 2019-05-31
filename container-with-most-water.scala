// https://leetcode.com/problems/container-with-most-water
// time complexity - O(N^2), space complexity - O(1)

object Solution {
    def maxArea(height: Array[Int]): Int = {
        var max_area: Int = 0
        for (i <- 0 to height.size-1) {
            for (j <- height.size-1 to i+1 by -1) {
                val area: Int = scala.math.min(height(i), height(j)) * scala.math.abs(j-i)
                max_area = scala.math.max(area, max_area)
            }
        }
        return max_area
    }
}