#!/usr/bin/env bash
echo "=====>Install nvm"
curl -o- https://raw.githubusercontent.com/creationix/nvm/v0.33.11/install.sh | bash
export NVM_DIR="${XDG_CONFIG_HOME/:-$HOME/.}nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"
source ~/.bashrc

# Issue for MacOS: dyld: Library not loaded: /usr/local/opt/icu4c/lib/libicui18n.62.dylib
if [ $(uname) == "Darwin" ]; then
	brew unlink python@2
	brew upgrade
fi	

echo "=====>Change node version"
node --version
nvm install 8.9.4
nvm use 8.9.4
node --version

echo "=====>Build node module"

cd ledger-core-samples/nodejs
# Speed up module's build
export JOBS=8
yarn
mkdir tmp
node tests/basic-test.js

LIB_VERSION=$(node tests/lib-version.js)

if [ -z "$CIRCLE_TAG" ]; then
	COMMIT_HASH=`echo $CIRCLE_SHA1 | cut -c 1-6`
	LIB_VERSION="$LIB_VERSION-rc-$COMMIT_HASH"
fi

echo "export LIB_VERSION=$LIB_VERSION" >> $BASH_ENV

echo "=====> Libcore version"
echo $LIB_VERSION