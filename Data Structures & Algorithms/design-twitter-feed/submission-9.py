class Twitter:
    def __init__(self):
        self.follows = {}
        self.posts = {}
        self.count = 0    

    def postTweet(self, userId: int, tweetId: int) -> None:
        if userId not in self.posts.keys():
            self.posts[userId] = []
            self.follows[userId] = []
        self.posts[userId].append((self.count, tweetId))
        self.count += 1


    def getNewsFeed(self, userId: int) -> List[int]:
        allPosts = list(self.posts[userId])
        for user in self.follows[userId]:
            allPosts.extend(list(self.posts[user]))
        allPosts = sorted(allPosts, key=lambda x: x[0])
        
        posts = []
        while allPosts and len(posts) < 10:
            time, post = allPosts[-1]
            allPosts.pop()
            posts.append(post)
        return posts 
            
        

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId not in self.follows.keys():
            self.follows[followerId] = []
            if followerId not in self.posts.keys():
                self.posts[followerId] = []
        if followeeId not in self.follows[followerId]:        
            self.follows[followerId].append(followeeId)
        

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.follows[followerId]: 
            self.follows[followerId].remove(followeeId)
