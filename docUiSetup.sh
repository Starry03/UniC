#!/bin/bash

./.venv/bin/python doc/docdb_gen.py
if [ $? == 0 ];
	then echo "Documentation generated successfully"
else
	echo "Documentation generation failed"
fi

echo "Building next-js"
cd ./doc/client
npm run build
if [ $? == 0 ];
	then echo "Next built successfully"
else
	echo "Next failed building"
fi