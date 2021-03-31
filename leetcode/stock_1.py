def maxProfit(self, prices: List[int]) -> int:
        answer = 0
        bought = sys.maxsize
        
        for price in prices:
            # Buy
            if bought > price:
                bought = price
            
            # Sell
            if price - bought > answer:
                answer = price - bought
                
        return answer
