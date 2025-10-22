class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        totalBottles = numBottles
        while numBottles >= numExchange:
            newBottles = numBottles // numExchange
            totalBottles += newBottles
            numBottles = newBottles + numBottles % numExchange
            

        return totalBottles

        