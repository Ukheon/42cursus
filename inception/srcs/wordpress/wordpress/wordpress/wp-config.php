<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'ukwon' );

/** MySQL database password */
define( 'DB_PASSWORD', '1234' );

/** MySQL hostname */
define( 'DB_HOST', 'mysql:3306' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         '?qPBjG#=zUt`k^2=4)D?~DzAUG~RAmcf=Fp!ZFBP!W~S9cHob%:[56&A68[EC:#l' );
define( 'SECURE_AUTH_KEY',  '4LZ3?u{sxwO6kfN5 Z^__;{6QEycsvtCgs]*W.g=6Wy[6YX%tFIx`q~wtx1[4~Y3' );
define( 'LOGGED_IN_KEY',    'wo$lG}yA!@Fq<r{zu-LX2d.isJ`ABgnLs5Y_E8{}/6AeU!CzN?l_TR4ycK-#=fBf' );
define( 'NONCE_KEY',        '1y#U>ZsyIH m6^VTF/<4EQVP@.<js3KPE,v#MX|_FB~S~F&SM(`wL`%7]iU{FXQU' );
define( 'AUTH_SALT',        '?Q6<}+nnU,OdO@dl:U&{KN]+ 9L49~mcM30R5.W!j0F}!iuAb*J)G*EpK$>K5{zx' );
define( 'SECURE_AUTH_SALT', 'pukjZ [KXmTjf6PCF7O}jPj]E@]u 1]/ay-OYQUge|X9,aLOxnXVY~]]q(Axxx(Y' );
define( 'LOGGED_IN_SALT',   '})v*~x=-D/`uz(?^v&O@c$qr``d2L_7w>;?dvP0J- ;0Vm;8F8m;XU3YhS]~56lY' );
define( 'NONCE_SALT',       'Pf[#oi/H1+WyOh{,]%C/u5:/Rsg?]{8VU#5c=u$~,W^,DGtN,^fi#7sonW42`[$f' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';