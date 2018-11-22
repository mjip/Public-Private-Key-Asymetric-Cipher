# Public-Private-Key-Asymmetric-Cipher
Checks the validity of public/private keys and encrypts/decrypts messages passed through the command line.

---------------------------------------

After compilation, this program can be called in two ways:
>$ ./a.out -CHECK <PUBLIC_KEY> <PRIVATE_KEY> <MODULO>

>$ ./a.out -CIPHER <filename> <KEY>

The first option checks to see if public_key, private_key and modulo can be used to form
an asymmetric cipher. In order to be valid keys, the public key can't be a multiple of the
modulo, the product of the public key and private key modulo the last argument is 1, 
the modulo is greater than the public key, and the public key is a prime. 

The second option encrypts the message contained in the file provided, using the public key.
It assumes a default modulo of 256 (ASCII character table) and encrypts each char of the 
message one at a time. It then creates a .cipher file to place the encrypted text in. The
text can be decrypted by running the .cipher file as the third arg and with the private key.
