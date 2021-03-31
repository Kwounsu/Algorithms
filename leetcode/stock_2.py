def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        bought_price = -1

        for day, price in enumerate(prices):
            # Last day of the world
            if day == len(prices) - 1:
                if 0 <= bought_price:  # SELL if you own stock
                    profit += price - bought_price
                    
            # BUY if 'you don't own stock' and 'price of next day goes up'
            elif bought_price == -1 and prices[day + 1] > price:
                bought_price = price
                
            # SELL if 'you own stock' and 'price of next day goes down'
            elif bought_price >= 0 and prices[day + 1] < price:
                profit += price - bought_price
                bought_price = -1

        return profit
