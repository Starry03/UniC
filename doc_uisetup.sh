#!/bin/bash

echo "Setting up the documentation environment"
echo "Creating virtual environment"

if [ -d "./.venv" ]; then
	echo "Virtual environment already exists, skipping creation."
else
	python3 -m venv ./.venv
	if [ $? == 0 ];
		then echo "Virtual environment created successfully"
	else
		echo "Virtual environment creation failed"
		exit 1
	fi
fi

./.venv/bin/python -m pip install --upgrade pip
./.venv/bin/python -m pip install -r requirements.txt
if [ $? == 0 ];
	then echo "Python dependencies installed successfully"
else
	echo "Python dependencies installation failed"
fi

# create postgres database
echo "Creating PostgreSQL database"
sudo -u postgres psql -c "CREATE DATABASE unic;"
sudo -u postgres psql -c "GRANT ALL PRIVILEGES ON DATABASE unic TO postgres;"

./.venv/bin/python doc/docdb_gen.py
if [ $? == 0 ];
	then echo "Documentation generated successfully"
else
	echo "Documentation generation failed"
fi

echo "Installing node dependencies"
cd ./doc/client && npm install
echo "Building next-js"
cd ./doc/client
npm run build
if [ $? == 0 ];
	then echo "Next built successfully"
else
	echo "Next failed building"
fi