#ifndef TWITTER_ACTIONS_h
#define TWITTER_ACTIONS_h

#define STATUS_PREFIX_LENGTH 7
#define STATUS_PREFIX "status="

int update_status(char*);
int get_friends_timeline(void);

#endif
