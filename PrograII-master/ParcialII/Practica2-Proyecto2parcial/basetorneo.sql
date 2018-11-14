-- phpMyAdmin SQL Dump
-- version 4.2.11
-- http://www.phpmyadmin.net
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 01-03-2018 a las 03:18:13
-- Versión del servidor: 5.6.21
-- Versión de PHP: 5.6.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de datos: `basetorneo`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `equipo`
--

CREATE TABLE IF NOT EXISTS `equipo` (
`id` int(11) NOT NULL,
  `nombre` varchar(30) COLLATE utf8_spanish_ci NOT NULL,
  `nombre_corto` varchar(30) COLLATE utf8_spanish_ci NOT NULL,
  `fecha` date NOT NULL,
  `direccion` varchar(50) COLLATE utf8_spanish_ci NOT NULL DEFAULT 'Opcional',
  `correo` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `web` varchar(25) COLLATE utf8_spanish_ci NOT NULL DEFAULT 'Opcional',
  `id_usuario` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=60 DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `equipo`
--

INSERT INTO `equipo` (`id`, `nombre`, `nombre_corto`, `fecha`, `direccion`, `correo`, `web`, `id_usuario`) VALUES
(54, 'xcarsadupdate', 'xcar_1', '2018-12-31', 'colon2', 'xcar02@gmail.com', 'xcars.com', 66),
(55, 'pollos', 'pollo', '2018-11-30', 'colon', 'correo@gmail.com', 'colon.com', 67),
(58, 'kolo', 'kb', '2017-01-10', 'tariba', 'luedge96@gmail.com', 'tariba.com', 70),
(59, 'TachiraFC', 'TFC', '1990-03-10', 'PUEBLO NUEVO', 'DTF@gmail.com', 'DTFC.com', 71);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `torneo_registro`
--

CREATE TABLE IF NOT EXISTS `torneo_registro` (
`id` int(11) NOT NULL,
  `nombre_torneo` varchar(30) CHARACTER SET utf8 COLLATE utf8_spanish_ci NOT NULL,
  `fecha_realizacion` date NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=25 DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `torneo_registro`
--

INSERT INTO `torneo_registro` (`id`, `nombre_torneo`, `fecha_realizacion`) VALUES
(14, 'tennis de mesa', '2010-02-23'),
(15, 'futbol ', '2018-06-20'),
(16, 'playa1', '0033-03-21'),
(17, 'hockey', '2018-09-02'),
(18, 'damas chinas', '1990-02-05');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `torneo_usuario`
--

CREATE TABLE IF NOT EXISTS `torneo_usuario` (
`id` int(2) NOT NULL,
  `id_user` int(2) NOT NULL,
  `nombre_torneo` varchar(30) NOT NULL,
  `fecha` date NOT NULL,
  `participantes` int(2) NOT NULL,
  `nivel` varchar(15) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=60 DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `torneo_usuario`
--

INSERT INTO `torneo_usuario` (`id`, `id_user`, `nombre_torneo`, `fecha`, `participantes`, `nivel`) VALUES
(36, 67, 'futbol', '2018-06-20', 4, 'Aficionados'),
(38, 67, 'playa1', '0033-03-21', 7, 'Aficionados'),
(50, 70, 'damas chinas', '1990-02-02', 3, 'Principiante'),
(51, 70, 'playa1', '0033-03-21', 5, 'Principiante'),
(52, 70, 'futbol', '2018-06-20', 5, 'Principiante'),
(53, 70, 'tennis de mesa', '2010-02-20', 2, 'Principiante'),
(54, 66, 'playa1', '0033-03-21', 3, 'Principiante'),
(56, 71, 'damas chinas', '1990-02-02', 3, 'Aficionados'),
(58, 70, 'hockey', '2018-09-02', 2, 'Principiante'),
(59, 66, 'futbol ', '2018-06-20', 5, 'Principiante');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usuario`
--

CREATE TABLE IF NOT EXISTS `usuario` (
`id` int(11) NOT NULL,
  `usuario` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `contra` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `admin` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=72 DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `usuario`
--

INSERT INTO `usuario` (`id`, `usuario`, `contra`, `admin`) VALUES
(66, 'prueba', '1010', 0),
(67, 'pollitos', 'pollitos', 0),
(70, 'kolo', '1234k', 0),
(71, 'DTFC', 'DT', 1);

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `equipo`
--
ALTER TABLE `equipo`
 ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `torneo_registro`
--
ALTER TABLE `torneo_registro`
 ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `torneo_usuario`
--
ALTER TABLE `torneo_usuario`
 ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `usuario`
--
ALTER TABLE `usuario`
 ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `equipo`
--
ALTER TABLE `equipo`
MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=60;
--
-- AUTO_INCREMENT de la tabla `torneo_registro`
--
ALTER TABLE `torneo_registro`
MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=25;
--
-- AUTO_INCREMENT de la tabla `torneo_usuario`
--
ALTER TABLE `torneo_usuario`
MODIFY `id` int(2) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=60;
--
-- AUTO_INCREMENT de la tabla `usuario`
--
ALTER TABLE `usuario`
MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=72;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
