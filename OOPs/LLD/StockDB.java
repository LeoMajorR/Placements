public class StockDB{
    class Stock{
        String name;
        int price; //primary key
        String symbol;
        String exchange;
        String information;
    }

    // for storing the LTP of the stock
    class LTP{
        String symbol;
        int ltp;
    }

    // for storing minute wise data of each stock
    class BankNifty{
        String symbol;
        String timeStamp;
        int price;
    }

    class Nifty{
        String symbol;
        String timeStamp;
        int price;
    }
}