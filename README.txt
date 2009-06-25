This Twitter client has three modes of operation:

1) If password/username is not set, it will ask for username and password and store it in the preferences file.

2) If no arguments are passed, and the password and username are already saved in the preference file,
it will retrieve the last updates from that user's feed.

3) If arguments are passed, and the password and username are in the preferences file, it will try to post them as a tweet to the account defined by the password/username in the preferences file.

0) Frank find this awesome twitter client, downloads it. After unpacking the
tarball, he goes through ./configure, make, make install and, voilà!, his new
twitter client is installed.

1) Frank invokes ctweet: a message politely asks him his username and password;
after typing them in, he receivves a confirmation message that they have been saved.

2) Frank invokes ctweet, and piping through less, he reads a nicely formatted
output of his friends' latest status updates, including their username,
@ replies, and the date.

3) Nawal  invokes ctweet -- inser arabic script here -- and the status displays as intended on twitter.com.
