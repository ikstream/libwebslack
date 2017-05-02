# __Libwebslack__

libwebslack provides an interface to send messages to slack
via the incomming webhooks system from a C program.

#### Depencies
`libcurl`
#### Usage
To send messages you first have to initialize the channel,
the webhook and username.
```
\\create a struct per team you want send messages
struct team_info *ti = malloc(sizeof(*ti));

\\set webhook url
if (set_webhook_url(ti, <your webhook here>)) {
     \\error handling
}

\\set the channel you want to post to (max 22 characters)
if (set_channel(ti, "#general")) {
     \\error handling
}

\\set the username you want to use (max 21 characters)
if (set_username(ti, "libwebslackbot")) {
     \\error handling
}

\\set emoji for your message (optional)
if (set_emoji(ti, ":ghost:") {
     \\error handling
}

if (set_message(ti, "your very important message")) {
     \\error handling
}

if (send_message(ti)) {
     \\error handling
}
```
#### Compiler and linker flags
As libwebslack uses libcurl, the compiler needs to know:
```$(pkg-config --libs --cflags libcurl)
```

#### TODO
libwebslack uses libcurl by now. This __should__ be changed in the
future to be based on standard libs only.
