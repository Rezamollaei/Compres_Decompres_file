This code implements a simple program for file compression and decompression using basic run-length encoding (RLE). Here's a summary:

Purpose:
Compresses or decompresses the contents of a text file using a custom RLE approach.
How It Works:
User Input: The user chooses between compression ('C') or decompression ('D').
Compression:
Consecutive repeated characters in source.txt are replaced with <character>!<count> (e.g., "aaa" becomes "a!3").
Single or non-repeated characters are written as-is.
The output is saved to compressed.txt.
Decompression:
Expands sequences with !<count> notation from compressed.txt back into their original form.
The output is written to decompressed.txt.
Key Details:
compress and decompress functions handle the main logic.
File error handling ensures files open successfully.
The program reports the number of characters processed or outputs an error message.
This demonstrates basic file I/O and run-length encoding logic in C.
