In a certain sense, a URL shortener is a giant hash table, which maps integer values to full URL strings.  The integer values are represented in the "shortened" URL by a short sequence of characters, which may encode this integer in something like base-64 notation.  An alphabet of 64 characters is used, each character representing 6 bits of an encoded number that is used as the key to the hash table.  We'll use the Latin alphabet in upper- and lower-case, the digits 0-9, and two additional characters that commonly have no significance in URLs to encode these values.  We'll use the dash (-) and period (.) characters for this purpose.

Obviously, my site will require some user interface, if only to allow people to add new URLs to the shortener.  But I'll want a quick way to identify URLs that are part of my UI, rather than URLs to be "expanded."  I'll declare that all URLs that are part of my site's UI must contain at least one slash (/) character after the one at the root of the URL path.  So the path "/img" would actually be a "shortened" URL that needed expanding, but "/img/foo.jpg" might be a reference to an image my site actually hosts.

The most common operation my site is going to have to perform, by far, is expanding a short URL to a full one.  So I'll design a piece of code that watches over all incoming HTTP requests, performing the following steps:

+ 1. Examine the "path" associated with the incoming URL.  If the path consists only of a single slash, or contains more than one slash, drop out into the "slow code path" that actually looks up a resource within my full Web application, whether static or dynamic.
+ 2. Drop the initial slash in the path and base-64 decode the remaining string to get the hash key.
+ 3. Look up the key in my master hash table to get the full URL.  If it's present, issue a "302 Redirect" status back to the browser, passing the stored URL in the "Location" field. (I can also do funky tricks like "framing" the URL if I want, by redirecting to part of my own site that generates the "frame" around the target URL.)
+ 4. If that key is not present in the hash table, I can issue a "404 Not Found" status, or redirect the user back to my home page.

One of the pages in my UI will provide a field for someone to add a new URL.  When someone does do this, my site code will do the following:

+ 1. Generate a 36-bit hash value from the URL, using any convenient algorithm.  (A 36-bit value can be represented in 6 base-64 encoded characters.)
+ 2. Attempt to add the user's specified URL to the hash table using that number as a key.  If the attempt fails, because another URL is already present in the hash table with that index, apply a "rehash" function to the hash value and retry this step. (If you find the same URL you're encoding, you can reuse the same key number.)
+ 3. Encode the key number as a base-64 string, and present the shortened URL to the user, in the form "http://erbo.ly/xxxxxx", where "xxxxxx" is the encoded key number.
I might also have a SOAP or REST API that does the same thing, allowing other services to use my URL shortener.  The API's URL would, like other URLs belonging to my UI, have more than one slash in its path. ("http://erbo.ly/api/add" would be a good endpoint name.)

The way the hash table is stored merits special examination.  Obviously, my hash table will have to be persistent, and may have to be accessible from many different Web servers (if I use a load-balancing scheme on the front end to handle all the incoming requests and share the load across multiple Web server nodes).  Some sort of high-performance NoSQL database would be ideal; I've previously used Apache CouchDB as the basis for a distributed hash table in another piece of software, for instance.  (Redis might also be a good choice here, as Zeeshan Ashraf points out.)  If it's that critical, though, I may write my own specialized implementation, as it doesn't have to store much, but it does have to be very fast at retrieval.   (But only if an off-the-shelf solution won't make the nut.)

Scaling Erbo.ly will primarily involve using additional Web servers on the front end behind a load balancer, to handle more incoming requests, and the use of extensive caching to resolve frequently-referenced "short" URLs without having to go all the way out to the master hash table every time.  This takes advantage of the fact that a URL shortener will have a very high read-to-write ratio on my master hash table, and entries will effectively never be erased.  Also, the simple process of resolving shortened URLs is handled by my top-level "filter" and doesn't involve session handling, so it's essentially stateless and thus highly amenable to parallelism.  We can also optimize by using the base-64 encoded integer value itself as the hash key, thus eliminating the "decode" step when the URL needs to be resolved.

I'm leaving out discussion of certain considerations, such as possible use of HTTPS for security, or the fact that, since I use a .ly domain name, the Libyan government won't want me shortening porn URLs or anything "immoral."  But these are things that would have to be figured out for an actual, working service.


## Design a url shortening service, like bit.ly

### Use Cases
+ 1. Shortening: take a url => return a much shorter url
+ 2. Redirection: take a short url => redirect to the original url
+ 3. Custom url
+ 4. High avaliablity of the system
    + 1. Analytics
    + 2. Automatic link expiration
    + 3. Manual link removal
    + 4. UI VS API

### Math

