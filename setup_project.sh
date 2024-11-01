#!/bin/bash

# Step 0.1: Initialize VST plugin project with core directories and repository setup

# Define the project name
PROJECT_NAME="CompanyPlugin"

# Create the core directory structure
mkdir -p "$PROJECT_NAME"/{Source/{Core,GUI,Presets},Resources/{Images/CompanyAssets,Presets},Tests/{DSP,GUI,Integration},Builds/{Windows,MacOS,Linux},Docs/{API,DSP,GUI,Testing}}

# Initialize a new Git repository
cd "$PROJECT_NAME" || exit
git init

echo "Project $PROJECT_NAME initialized with core directories and Git repository."
