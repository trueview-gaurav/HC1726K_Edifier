# Docker Setup (Ubuntu Host)

This project builds Yocto toolchains inside a **Ubuntu 16.04 container** for compatibility with the Yocto 2.1 (krogoth) build environment.

This document describes how to set up Docker on an Ubuntu host (validated on Ubuntu 24.04).

> If Docker is already installed and working, you can skip this document and proceed to `BUILDING.md`.
> 

---

## 1. Remove legacy Docker packages (optional)

```bash
$ sudo apt remove docker docker-engine docker.io containerd runc -y
```

## 2. Install Docker from Docker’s official apt repository

```bash
$ sudo apt update && sudo apt upgrade -y
$ sudo apt install -y ca-certificates curl gnupg
$ sudo install -m 0755 -d /etc/apt/keyrings
$ curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo tee /etc/apt/keyrings/docker.asc > /dev/null
$ sudo chmod a+r /etc/apt/keyrings/docker.asc
$ echo "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
$ sudo apt update
```

---

## 3. Install Docker Engine and Docker Compose plugin

```bash
$ sudo apt install -y docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
```

---

## 4. Start Docker and enable it at boot

```bash
$ sudo systemctl start docker
$ sudo systemctl enable docker
```

---

## 5. Verify Docker is working

```bash
$ sudo docker run hello-world
```

---

## 6. Allow running Docker without `sudo` (recommended)

```bash
$ sudo groupadd docker
$ sudo usermod -aG docker $USER
```

> The `docker` group often is created automatically during installation.
> If it doesn't already exist, you should create it manually.
>

Log out and log back in, then verify:

```bash
$ docker run hello-world
$ docker compose version
```

---

## 7. (Optional) Change Docker data-root (recommended approach)

If the default Docker storage directory is too small, move it to a larger disk.

### Option A: Use `/etc/docker/daemon.json` (recommended)

```bash
sudo systemctl stop docker
sudo install -m 0755 -d /etc/docker
sudo tee /etc/docker/daemon.json > /dev/null<<'EOF'
{
  "data-root": "<Your Path>/data/docker"
}
EOF
sudo systemctl start docker
```

Verify:

```bash
docker info | grep -i "Docker Root Dir"
```

### Option B: Symlink `/var/lib/docker` (works in some environments)

```bash
$ sudo systemctl stop docker
$ sudo mv /var/lib/docker <Your Path>/data/docker
$ sudo ln -s <Your Path>/data/docker /var/lib/docker
$ sudo systemctl start docker
```

> Note: The `daemon.json` approach is generally more robust across upgrades and different host configurations.
> 

---

## 8. Next step

Proceed to `BUILDING.md` and run the one-shot build script:

```
$ Scripts/host-build-all.sh --init-conf
```

