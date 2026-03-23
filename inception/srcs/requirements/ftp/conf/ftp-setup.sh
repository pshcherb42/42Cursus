#!/bin/bash

# Create FTP user from environment variables
# FTP_USER and FTP_PASSWORD must be set in .env

if id "$FTP_USER" &>/dev/null; then
    echo "FTP user '$FTP_USER' already exists."
else
    echo "Creating FTP user '$FTP_USER'..."
    useradd -m -d /var/www/html/wordpress -s /bin/bash "$FTP_USER"
    echo "$FTP_USER:$FTP_PASSWORD" | chpasswd
    echo "FTP user created."
fi

# Ensure the WordPress volume is owned by the FTP user
chown -R "$FTP_USER":"$FTP_USER" /var/www/html/wordpress 2>/dev/null || true

echo "Starting vsftpd..."
exec vsftpd /etc/vsftpd.conf