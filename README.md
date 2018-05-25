# QOAuth2Test
Google Sign In over QtNetworkAuth example

This is an example of a very simple usage of QtNetworkAuth.
It is based on an Qt blog post http://blog.qt.io/blog/2017/01/25/connecting-qt-application-google-services-using-oauth-2-0/.

In order to work, you have to follow the procedure of the blog post.
When you're done, change in the file qoauth2test.cpp the following two lines with the information given by Google.
<pre>
    QString clientId = "copy your whatever.apps.googleusercontent.com URL here";
    QString clientSecret = "copy your secret here";
</pre>

Please note that, on some computers, the server handling the callback may take time to be created.
