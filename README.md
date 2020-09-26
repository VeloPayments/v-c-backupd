Blockchain Backup Service
=========================

The blockchain backup service provides an encrypted offsite store of the
blockchain. For the moment, the service is a polling service, but in the
immediate future, it will be converted to a sentinel -- meaning that it is
automatically notified by the blockchain when there are new blocks to process.

This service runs in a foreground mode with console logging and in a daemon
mode.  In the foreground mode, ctrl-C will safely end the service. This mode is
most useful for making a complete backup, as it will provide information about
how far along the backup is.  For incremental or continuous backups, the daemon
mode is more useful.  The daemon can be safely shut down by sending it a TERM
signal via kill.

Upon startup, the backup service will attempt to open and read the backup file.
If the file does not exist, it will create this file. If the file does exist, it
will seek to the end of the file to read the last record header.  The service
will then prompt for a password which is used to unlock a private key stored in
the backup file. This key is used to encrypt the backup file and to verify chunk
integrity.  Another password prompt will be used -- if needed -- to decrypt the
private key file used to communicate with the blockchain agent instance.

The backup service supports several command-line options used to inform it about
the location of a blockchain agent instance, the location of the private key
file used to communicate with this instance, and the name of the backup file.

Restoring
---------

vctool can be used to restore a backup to a fresh agentd instance. More
instructions for doing this are provided in the vctool documentation.
