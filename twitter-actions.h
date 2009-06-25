#ifndef TWITTER_ACTIONS_h
#define TWITTER_ACTIONS_h

#define STATUS_PREFIX_LENGTH 7
#define STATUS_PREFIX "status="
#define MAX_TWEET_LENGTH 140

int update_status(char*);
int get_friends_timeline(void);

#endif
