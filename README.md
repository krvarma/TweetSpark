TweetSpark using Node-RED and Spark Core
----------------------------------------

After seeing [this project](http://www.hackster.io/projects/e/pinoccio/950-tweet-all-the-things) in Hackster.io, I thought doing same using Spark Core and Node-RED. Here a project I created. 

TweetSpark uses Node-RED Twitter node, a Function Node and Spark Core Input node 	I wrote. The Twitter node listens for tweets starting with **spark-call/spark-read**. Once such a tweet is received, it passes the tweet to the Function node which parses the tweet. TweetSpark expects the tweet in the form:

    spark-call/spark-read <variable name/function name> <function parameter>

The Function node parses this tweet and separate the function/variable name and parameter. This is passed to the Spark Core node with call the function or read the variable. Once the result is received TweetSpark tweets back the result (note that Twitter does not allow same tweets within 15 minutes).

**Screenshots**

![Node-RED Flow](https://raw.githubusercontent.com/krvarma/TweetSpark/master/screenshots/flow.png)

![Twitter](https://raw.githubusercontent.com/krvarma/TweetSpark/master/screenshots/twitter.png)

**Demo Video**

[TweetSpark Demo Video](https://www.youtube.com/watch?v=iSbWnAfFnT0)