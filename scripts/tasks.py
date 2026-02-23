import subprocess
import sys


def dev() -> None:
    subprocess.run(
        ["zensical", "serve", "--dev-addr", "localhost:9000", "-o"],
        check=True,
    )


def build() -> None:
    subprocess.run(["zensical", "build"], check=True)


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: tasks.py [dev|build]")
        sys.exit(1)

    cmd = sys.argv[1]

    if cmd == "dev":
        dev()
    elif cmd == "build":
        build()
    else:
        print(f"Unknown command: {cmd}")
        sys.exit(1)