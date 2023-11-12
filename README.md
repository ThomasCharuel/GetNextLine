docker build -t get-next-line .

docker run -it -v "$(pwd):/project" get-next-line
