How to build a News Feed such as Facebook's news feed?
======================================================

#### Background
Users in most social networking sites are describable in terms of a social graph. The relationships between users are represented by adjacency lists. If Jack and Jill are friends, they are said to be adjacent. This is known as an "edge" in the graph.

#### Determininig Importance
You'll likely want to rank edges by importance rather than simply the most recent updates, meaning that you need to calculate some sort of score. Facebook's _EdgeRank_ was described by the formula $\sum{e} = u_e w_e d_e$. wherein $\sum{e}$ is the sum of the edge's rank, $u_e$ is the affinity score with the user who created the edge, $w_e$ is the weight for the content type, and $d_e$ is a time decay factor.

Calculating a friend's affinity score can be done someting like this:$\sum{i} = l_i n_i w_i$, wherein $\sum{i}$ is the sum of the interactions with that friend, $l_i$ is the time since your last interaction(this would need to be weighted so that 1 day > 30 days), $n_i$ is the number of interacts, and $w_i$ is the weight of thoes interactions. This method allows you to rank friends in a separate database and then perhaps only show ten updates from the ten closest friends, which isn't a bad idea considering few of us are likely to have more close friends than this.

#### What to Store
Determining what data to store depends on your font-end(including what activities your users participate in) and your back-end. I'll describe some general information you can store. Italics are special, optional information you might want or need depending on your schema.

Activity(id, user_id, source_id, activity_type, edge_rank, parent_id, parent_type, data, time)

+ **user_id:** user who generated activity
+ **source_id:** record activity is related to
+ **activity_type:** type of activity(photo album, comment, etc.)
+ **edge_rank:** the rank for this particular activity
+ **parent_type:** the parent activity type(particular interest, group, etc.)
+ **parent_id:** primary key id for parent type
+ **data:** serialized object with meta-data

Assuming you're using MySQL as your database store, you can index on (user_id, time) and then perform your basic queries. An example feed row for a photo would be: `(id: 1, user_id: 1, source_id: some_source, activity_type: PHOTO, data:(photo_id: 1, photo_name: Getting married))`.

In MySQL, your tables would be heavily denormalized since performing joins will hurt perpormance.

#### Potential Problems

+ **Visibility:** must show interesting activities
+ **Performance:** sorting time must be minimized
+ **Publishing:** multiples points of failure depending on your publish method

#### Publishing Methods
_**"Push" Model, or Fan-out-on-write**_

This method involves denormalizing the user's activity data and pushing the metadata to all the user's friends at the time in occurs. You store only one copy of the data as in the schema above, then push pointers to friends with the metadata. The problem with this method is that if you have a large fan-out(a larege number of followers), you run the risk of this breaking whild your feed accumulateds a backlog. If you go with this startegy, you also risk a large number of disk seeks and random writes. You'll want some sort of write optimized data store suck as Cassandra, HBase, or BigTable.

_**"Pull" Model, or Fan-out-on-load**_

This method involves keeping all recent activity data in memory and pulling in (or fanning out) that data at the time a user loads their home page. Data doesn't need to be pushed out to all subscribers as soon as it happens, so no bak-log and no disk seeks. The problem with this method is that you may fail to generate a user's news feed altogether. To mitigate this risk, you should have a fallback mechanism in place that approximates the user's feed or serves as a god algernative.