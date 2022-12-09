import React from 'react';
import { StyleSheet, FlatList, View } from 'react-native';
import Header from './components/Header';
import { useState } from 'react';
import ListItem from './components/ListItem';
import Form from './components/Form';

export default function App() {
  const [listOfItems, setListOfItems] = useState([])

const addHandler = (text) => {
  setListOfItems((list) => {
    return [
      { text : text, key: Math.random().toString(36).substring(7) },
      ...list
    ]
  })
}

const deleteHandler = (key) => {
  setListOfItems((list) => {
    return list.filter(listOfItems => listOfItems.key != key)
  })
}

  return (
    <View style={styles.forView}>
      <Header/>
      <Form addHandler={addHandler} />
      <View>
        <FlatList data={listOfItems} renderItem={({ item }) => (
          <ListItem el={item} deleteHandler={deleteHandler} />   
        )} />
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  forView: {
    flex: 1,
    width: '100%',
  }
});
