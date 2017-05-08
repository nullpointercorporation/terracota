echo "Terracota game installation"
echo "Installation of required packages"
sudo apt-get install libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev libsdl2-mixer
echo "Unpack ijengine.taz.gz"
cd lib
tar -vzxf ijengine-0.0.5.tar.gz
echo "Install ijengine"
make
echo "Copy to from engine to system"
sudo make install
echo "Install the game"
cd ..
make