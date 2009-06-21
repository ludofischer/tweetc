This Twitter client has three modes of operation:

1) If no arguments are passed and password/username is not set, it will ask for username and password and store it in the preferences file.

2) If executed without arguments, and the password and username are already saved in the preference file, it will retrieve the last updates from that user's feed.

3) If there are any arguments, it will try to post them as a tweet to the account defined by the password/username in the preferences file. If there is no preference file, or the file does not contain
a username/password, it will complain and exit. 
