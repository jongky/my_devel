var tar = require('tar-fs')
var fs = require('fs')
 
// packing a directory 
tar.pack('./').pipe(fs.createWriteStream('my-tarball.tar'))

// extracting a directory 
fs.createReadStream('./my-tarball.tar').pipe(tar.extract('./my-other-directory'))
 