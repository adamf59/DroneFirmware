echo "===Purge pre-existing binaries==="
echo "Press Enter to execute. Any files in bin will be removed!"
read pauser
echo "Deleting files..."
rm -r bin
echo "Re-creating bin folder"
mkdir bin
echo "Purge complete!"