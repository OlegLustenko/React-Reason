const path = require('path');
const webpack = require('webpack');
const HtmlWebpackPlugin = require('html-webpack-plugin');

const resolvePath = fileName =>
  path.resolve(__dirname, 'src', 'assets', fileName);
const appHtml = resolvePath('index.html');

console.log(appHtml);

module.exports = {
  // Entry file can be a Reason or OCaml file
  entry: './src/main.re',
  output: {
    filename: './out.js',
    path: path.resolve(__dirname, 'dist')
  },
  module: {
    rules: [
      // Set up Reason and OCaml files to use the loader
      {
        test: /\.(re|ml)$/,
        use: 'bs-loader',
        include: path.resolve(__dirname, 'src')
      },
      {
        test: /\.js$/,
        use: 'babel-loader',
        include: path.resolve(__dirname, 'src')
      }
    ]
  },
  plugins: [
    new webpack.HotModuleReplacementPlugin(
      {
        // multiStep: true
      }
    ),
    new HtmlWebpackPlugin({
      inject: true,
      template: appHtml
    }),
    new webpack.NamedModulesPlugin()
  ],
  node: {
    dgram: 'empty',
    fs: 'empty',
    net: 'empty',
    tls: 'empty'
  },
  resolve: {
    // Add .re and .ml to the list of extensions webpack recognizes
    extensions: ['.re', '.ml', '.js']
  },
  devServer: {
    inline: true,
    hot: true,
    open: true,
    watchOptions: {
      ignored: /node_modules/
    },
    port: 3000,
    overlay: true,
    clientLogLevel: 'error',
    historyApiFallback: {
      // Paths with dots should still use the history fallback.
      // See https://github.com/facebookincubator/create-react-app/issues/387.
      disableDotRule: true
    },
    compress: true
  }
};
