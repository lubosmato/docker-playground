<script setup lang="ts">
import { ref, watch } from 'vue'

const fibNum = ref("1")
const imageData = ref("")

watch(fibNum, async (newValue) => {
  const n = parseInt(newValue, 10)
  if (n == NaN) return

  const res = await fetch("/api/fib/", {
    method: "POST",
    body: n.toString()
  })

  if (res.status != 200) return

  const b64Data = await res.text()
  imageData.value = `data:image/jpeg;base64, ${b64Data}`
})

</script>

<template>
  <div class="container">
    <h1>Hellsoft</h1>
    <em>Protože v pekle je ještě dobře</em>
    <input class="form-control" type="number" v-model="fibNum">

    <img class="mt-4" :src="imageData"/>
  </div>
</template>

<style scoped>
img {
  border: 2px solid rgb(245, 245, 245);
  border-radius: 4px;
}
em {
  font-size: 9px;
  color: rgb(241, 241, 241);
}
</style>
